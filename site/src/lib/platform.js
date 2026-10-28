// The platform the visitor's browser says it runs on, as the id of a release
// archive (`darwin-arm64`), or "" when none fits. Read in the browser only.

export function client_platform() {
	const agent = navigator.userAgent;
	if (/Windows/.test(agent)) return 'windows-x64';
	if (/Macintosh|Mac OS X/.test(agent)) return 'darwin-arm64';
	if (/Linux/.test(agent) && !/Android/.test(agent)) return 'linux-x64';
	return '';
}
