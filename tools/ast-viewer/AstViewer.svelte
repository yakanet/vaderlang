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
    const input = Object.fromEntries(Object.keys(files).map(file => [file, {start: 0, end: 0}]))

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

    function jsonEditor(node: HTMLElement, content: string) {
        const view = new EditorView({
            doc: JSON.stringify(content, null, 2),
            parent: node,
            extensions: [
                basicSetup,
                highlight_field,
                json(),
                EditorView.editable.of(false)
            ]
        });
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