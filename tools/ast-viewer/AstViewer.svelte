<script lang="ts">
    import {basicSetup} from "codemirror"
    import {Decoration, type DecorationSet, EditorView} from "@codemirror/view"
    import {json} from "@codemirror/lang-json"
    import {StateEffect, StateField} from '@codemirror/state';

    let {
        parsed,
        files
    }: { parsed: any, files: Record<string, string> } = $props();

    const views = new Map<string, EditorView>();
    const input = $state(Object.fromEntries(Object.keys(files).map(file => [file, {start: 0, end: 0}])))

    function vaderEditor(node: HTMLElement, {name, content}: { name: string, content: string }) {
        const view = new EditorView({
            doc: content,
            parent: node,
            extensions: [
                basicSetup,
                highlight_field,
                EditorView.editable.of(false)
            ]
        });
        views.set(name, view);
        return {
            destroy: () => view.destroy(),
        }
    }

    function jsonEditor(node: HTMLElement, content: unknown) {
        const jsonContent = JSON.stringify(content, null, 2);
        const lines = jsonContent.split('\n');
        const view = new EditorView({
            doc: jsonContent,
            parent: node,
            extensions: [
                basicSetup,
                highlight_field,
                json(),
                EditorView.editable.of(false)
            ]
        });
        view.dom.addEventListener('click', (event) => {
            const pos = view.posAtCoords({x: event.clientX, y: event.clientY});
            const line = view.state.doc.lineAt(pos ?? -1);
            if (!line) {
                return;
            }
            if (line.text.trim().startsWith('"location":')) {
                const locationLines = lines.slice(line.number, line.number + 12)
                let locationJson = `{${locationLines.join('').trim()}`;
                if (locationJson.endsWith(',')) {
                    locationJson = locationJson.slice(0, locationJson.length - 1)
                }
                const location = JSON.parse(locationJson)
                if (location.file) {
                    input[location.file].start = location.start.offset;
                    input[location.file].end = location.end.offset;

                    const view = views.get(location.file)!;
                    const effects: StateEffect<any>[] = [set_highlight.of(input[location.file])];
                    view.dispatch({effects})
                }
            }
            // Ajoutez ici le code que vous souhaitez exécuter lors du clic sur la ligne
        })
        return {
            destroy: () => view.destroy(),
        }
    }

    const set_highlight = StateEffect.define<{ start: number; end: number } | null>();
    const highlight_field = StateField.define<DecorationSet>({
        create() {
            return Decoration.none;
        },
        update(highlights, tr) {
            for (let effect of tr.effects) {
                if (effect.is(set_highlight)) {
                    if (effect.value) {
                        const {start, end} = effect.value;
                        const deco = Decoration.mark({class: 'highlight'}).range(start, end);
                        return Decoration.set([deco]);
                    } else {
                        return Decoration.none;
                    }
                }
            }
            return highlights.map(tr.changes);
        },
        provide: (field) => EditorView.decorations.from(field)
    });


    function handleClick(event: Event, name: string) {
        event.preventDefault();
        const view = views.get(name)!;
        const effects: StateEffect<any>[] = [set_highlight.of(input[name])];
        view.dispatch({effects})
    }
</script>

<div class="viewport">
    <div class="files">
        {#each Object.entries(files) as [name, content]}
            <h3>{name}</h3>
            <div use:vaderEditor="{{name, content}}"></div>
            <form onsubmit={($event) => handleClick($event,name)}>
                <input type="number" bind:value={input[name].start}/>
                <input type="number" bind:value={input[name].end}/>
                <button>highlight</button>
            </form>
        {/each}
    </div>
    <div class="ast">
        <div use:jsonEditor={parsed}></div>
    </div>
</div>

<style>
    :global(body) {
        margin: 0;
    }

    .viewport {
        display: grid;
        grid-template-columns: 1fr 1fr;
        min-height: 100vh;
    }

    .viewport > * {
        max-height: 100vh;
        overflow: auto;
    }

    .files {
        padding: 0 1rem;
    }

    :global(.highlight) {
        background: #FF000033;
    }

    .ast {
        border-inline-start: 1px solid #aaa;
    }
</style>