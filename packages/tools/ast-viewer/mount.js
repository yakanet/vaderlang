import {mount} from 'svelte';
import AstViewer from "./AstViewer.svelte";

mount(AstViewer, {
    target: document.body,
    props: {
        files: PARSED_FILES,
        parsed: PARSED_PROGRAM
    }
})