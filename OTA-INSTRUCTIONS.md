# FW1906 trial 1: backup and OTA

Untested on hardware. Successful Actions checks establish compilation and automated mapping/image checks only. This changes every FW1906 output from G,R,B,CW,WW,0 to CW,WW,0,G,R,B, with inverse pixel reads. Other protocols and saved pin configuration are unchanged.

Before upload:
1. Open the controller IP in a browser on the same network.
2. Config > Security & Updates > Backup & Restore: download configuration and presets. Check both files contain data. Keep them private and record Wi-Fi credentials separately.
3. Photograph output GPIOs, types, start/count, color order, white/CCT settings, reversal, relay polarity, buttons and usermods. Preserve GPIO2/4 outputs and GPIO18 relay, plus all other saved assignments. Photos also showed GPIO16 output, GPIO17 button, GPIO12 LED on/off and GPIO15/32 usermod reservations.
4. Obtain original firmware for the exact Gledopto model. Configuration exports are not firmware backups. Full 4MB flash backups require safe serial access and esptool, and are for serial recovery only. Do not factory reset or erase flash.

Upload:
1. Wait for a successful Build FW1906 trial firmware run. Download and extract its WLED-ESP32-4MB-FW1906-TRIAL1-OTA artifact.
2. Confirm it contains WLED_16.0.1_ESP32_4MB_FW1906_TRIAL1_OTA.bin, SHA256SUMS.txt and build-info.json. The manifest records size and source commits. Build checks reject an oversized image or incorrect ESP32/4MB header.
3. Reduce brightness, pause effects, keep power stable. Open Config > Security & Updates > Manual OTA Update (or /update).
4. Upload ONLY the named .bin. Never upload a ZIP, filesystem image, bootloader, partition table, full-flash backup or merged factory image. Do not bypass an update validation failure.
5. Wait for restart, refresh browser, and verify all backed-up GPIOs, relay polarity and LED settings. UI version remains 16.0.1; use the manifest and checksum to identify this trial.

Test at low brightness:
Use Solid effect, affected outputs set to FW1906, original GPIO/count, GRB order, no white swap, and automatic white disabled/manual-only. Test red, green and blue separately with white zero. Then RGB black with white raised and each CCT endpoint. Check off is dark, relay behavior and a moving effect. Record every setting change. If only warm/cold are reversed, record this separately before trying white swap.

Assumptions:
Exact model, fourth connector mapping, chipset, wire order, warm/cold assignment, existing partition table and vendor customizations remain unverified. Four connectors do not establish four independent data GPIOs. Source is upstream v16.0.1, commit 29b389df1c1aaec6ff53aea742d17063b985906c, classic ESP32, 4MB DIO, standard 1MB-filesystem partitions with 1,572,864-byte OTA slots and AudioReactive. This is not a fresh-flash board configuration. Normal OTA preserves existing partitions/settings; compatibility with the actual device layout has not been measured. Mixed FW1906 strips needing different wire orders are not supported by this trial.

Rollback:
While web UI works, upload the original compatible vendor OTA application image; restore config/presets if needed. A full-flash backup requires serial recovery and cannot be uploaded to the OTA page. If UI fails, use exact-model recovery instructions. Power cycling does not guarantee rollback.

For another trial, collect R/G/B/cold/warm results, output tested, model label, LED settings and /json/info. Never publish credentials or private configuration backups to GitHub.
