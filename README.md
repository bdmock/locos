# WLED FW1906 trial firmware build

This repository builds upstream WLED **16.0.1**, commit `29b389df1c1aaec6ff53aea742d17063b985906c`, for a classic ESP32 with 4MB flash. It changes FW1906 byte order to `CW,WW,0,G,R,B` and retains saved pin configuration. It does not change the Android app.

The build runs on pushes affecting the build files, or manually from **Actions → Build FW1906 trial firmware → Run workflow**. After a successful run, download **WLED-ESP32-4MB-FW1906-TRIAL1-OTA** from its Artifacts section and extract it. Only upload the `.bin` inside using WLED's Manual OTA Update page.

Compilation, mapping checks, image header checks, and an application-size limit of **1,572,864 bytes** must all pass before the firmware artifact is published. This does not establish hardware compatibility. **Untested on hardware.** Read `OTA-INSTRUCTIONS.md` before uploading, and back up configuration, presets, and original firmware first.

The workflow fetches upstream source directly; no account credentials, Wi-Fi settings, or controller backups belong in this repository. Actions gets read-only repository access. Dependency versions follow the upstream build configuration, including its moving references.
