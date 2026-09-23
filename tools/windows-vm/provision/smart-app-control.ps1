# tools/windows-vm/provision/smart-app-control.ps1 -- turn Smart App Control off.
#
# Windows 11 starts it in evaluation mode and may switch it to enforcing on its
# own. Enforcing, it blocks an unsigned executable it has no reputation for,
# which is every stage a bootstrap build produces: `stage1.exe` is refused with
# "An Application Control policy has blocked this file". Off is permanent for
# this guest (Windows cannot turn it back on without a reinstall) and takes
# effect at the next boot.

$ErrorActionPreference = 'Stop'
Set-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\CI\Policy' `
    -Name VerifiedAndReputablePolicyState -Value 0 -Type DWord
