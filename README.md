# ESP32-Learning Journey — Repo Skeleton & Week‑by‑Week Plan

> **Purpose:** a ready-to-use README template, project skeleton, branch/PR/issue templates, sample `main.cpp`, `platformio.ini`, commit-message guide, daily tasks for Week 1, and a full 12‑week/quarterly roadmap you can follow with \~1 hour/day. Drop this into a GitHub repo (`esp32-learning-journey`) and start working; everything below is copy/paste ready.

---

## 1) Repo structure (suggested)

```
esp32-learning-journey/
├── .github/
│   ├── PULL_REQUEST_TEMPLATE.md
│   └── ISSUE_TEMPLATE.md
├── week1_blinky/
│   ├── src/
│   │   └── main.cpp
│   ├── include/
│   ├── docs/
│   │   └── wiring.jpg
│   └── README.md
├── templates/
│   ├── README_project_template.md
│   └── CONTRIBUTING.md
├── .gitignore
├── platformio.ini
└── roadmap.md
```

---

## 2) `week1_blinky/README.md` (template)

> This file is provided as a ready template inside the repo skeleton. Use it and fill the placeholders.

**Filename:** `week1_blinky/README.md` (already in this skeleton)

Template fields include: project objective, hardware list, wiring, build & upload steps (PlatformIO), run/demo steps, expected output, troubleshooting tips, branch & PR notes, changelog, licenses.

---

## 3) Minimal `platformio.ini` (project root)

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
build_flags =
  ; add build flags here if needed

[env:esp32dev_debug]
platform = espressif32
board = esp32dev
framework = arduino
build_type = debug
monitor_speed = 115200
```

---

## 4) Minimal `week1_blinky/src/main.cpp` (Arduino/PlatformIO)

```cpp
#include <Arduino.h>

const uint8_t LED_PIN = 2; // common on many ESP32 DevKitC boards
const uint8_t BUTTON_PIN = 0; // example, adjust to your wiring

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println("ESP32 Blinky Ready");
}

void loop() {
  static unsigned long last = 0;
  static int state = 0;

  // Read button (active low with INPUT_PULLUP wiring)
  bool btn = digitalRead(BUTTON_PIN) == LOW;

  // If button pressed, blink pattern; else keep LED off
  if (btn) {
    unsigned long now = millis();
    if (now - last >= 300) {
      last = now;
      state = (state + 1) % 2;
      digitalWrite(LED_PIN, state);
      Serial.println(state ? "LED ON" : "LED OFF");
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

---

## 5) `.gitignore` recommended entries

```
.vscode/
.env
*.pio/
.pioenvs/
build/
.DS_Store
*.bin
*.elf
*.pio
```

---

## 6) `.github/PULL_REQUEST_TEMPLATE.md` (short, actionable)

```
## Summary
<!-- Short description of changes -->

## What I changed
-

## How to test
1.
2.

## Checklist
- [ ] Compiles locally
- [ ] README updated if needed
- [ ] Relevant docs/images included

## Notes
<!-- Anything maintainer should know -->
```

## 7) `.github/ISSUE_TEMPLATE.md` (for tracking bugs/ideas)

```
---
name: Bug report
---

**Describe the bug**
A clear and concise description of what the bug is.

**Steps to reproduce**
1.
2.

**Expected behavior**

**Screenshots / Logs**

**Environment (board, PlatformIO version)**

**Additional context**
```

---

## 8) `templates/README_project_template.md` (for future weeks)

This is a concise project README you can copy into each `weekX_...` folder. It contains sections: objective, hardware, wiring, build/upload, usage, notes, test plan, expected results, screenshots, changelog.

---

## 9) Commit message style guide (conventional-ish)

* `feat:` new feature (e.g. `feat: add button control`)
* `fix:` bug fix
* `docs:` documentation only changes
* `chore:` build/test/file changes
* `test:` adding tests

*Write short subject (<=50 chars) and an optional body describing the why.*

---

## 10) Branching & PR conventions

* `main` = stable, release-ready content
* `dev` = integration branch for your work (optional)
* Feature branches: `feature/week1/blink`, `feature/week2/uart_cli`, `fix/week3/typo`
* PR title format: `feat(week1): add button control for blinky`
* Always open PR from your branch → review → merge using GitHub UI (use `squash and merge` if small commits)

---

## 11) Week 1 Daily deliverables (copy of earlier plan) — what to push each day

* **Day1:** repo skeleton and empty `week1_blinky/README.md` (commit `chore: init repo skeleton`)
* **Day2:** `src/main.cpp` blink code (commit `feat(week1): add blinky example`)
* **Day3:** updated blink pattern code and README (commit `feat(week1): modify blink pattern`)
* **Day4:** button control implemented and wiring image (commit `feat(week1): add button control`)
* **Day5:** docs complete (`docs/` + README update) (commit `docs(week1): add wiring and usage`)
* **Day6:** demo image/video `docs/` (commit `docs(week1): add demo photo`)
* **Day7:** branch + PR simulation and merge (commit `docs: add learning journey note`)

---

## 12) Full Course Skeleton (weeks 1–12 & monthly checkpoints)

> The full week-by-week tasks and deliverables (W1–W12) are included in `roadmap.md` inside this repo skeleton. It repeats the detailed weekly roadmap I previously provided and also lists: branch names, PR checklists, which files to include, and what to screenshot / record as evidence.

---

## 13) GitHub Actions (CI for PlatformIO) — **Ready-to-copy workflow**

> This builds your Week‑1 project on every push/PR. It caches PlatformIO and pip to speed up runs and uploads the compiled firmware as an artifact.

**Create file:** `.github/workflows/platformio.yml`

```yaml
name: PlatformIO CI

on:
  push:
    branches: [main, dev]
    paths:
      - 'platformio.ini'
      - 'week1_blinky/**'
      - '.github/workflows/platformio.yml'
  pull_request:
    branches: [main, dev]
    paths:
      - 'platformio.ini'
      - 'week1_blinky/**'
      - '.github/workflows/platformio.yml'

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v4

      - name: Set up Python
        uses: actions/setup-python@v5
        with:
          python-version: '3.x'

      - name: Cache pip
        uses: actions/cache@v4
        with:
          path: ~/.cache/pip
          key: ${{ runner.os }}-pip-${{ hashFiles('**/requirements.txt') }}
          restore-keys: |
            ${{ runner.os }}-pip-

      - name: Install PlatformIO
        run: pip install -U platformio

      - name: Cache PlatformIO core
        uses: actions/cache@v4
        with:
          path: ~/.platformio
          key: ${{ runner.os }}-platformio-${{ hashFiles('platformio.ini') }}
          restore-keys: |
            ${{ runner.os }}-platformio-

      - name: Show versions
        run: |
          pio --version
          python --version

      - name: Update PIO platforms & libs
        run: pio update

      # Build Week-1 project (note the -d path to the project dir)
      - name: Build (esp32dev)
        run: pio run -d week1_blinky -e esp32dev

      - name: Build (esp32dev_debug)
        run: pio run -d week1_blinky -e esp32dev_debug

      - name: Upload firmware artifacts
        uses: actions/upload-artifact@v4
        with:
          name: week1_blinky-firmware
          path: |
            week1_blinky/.pio/build/esp32dev/firmware.bin
            week1_blinky/.pio/build/esp32dev_debug/firmware.bin
          if-no-files-found: warn
```

**Commit guide**

1. Create folders: `.github/workflows/`
2. Add the YAML above to `platformio.yml`
3. Commit: `ci: add PlatformIO build workflow`
4. Push & open a PR; CI will auto-run and attach `firmware.bin` as an artifact when it compiles.

**README badge (optional)**

Add this near the top of your repo `README.md`:

```md
![PlatformIO CI](https://github.com/<YOUR_USERNAME>/esp32-learning-journey/actions/workflows/platformio.yml/badge.svg)
```

> Replace `<YOUR_USERNAME>` with your GitHub handle.

---

## 14) How to use this skeleton quickly (3 steps)

1. Create a new GitHub repo named `esp32-learning-journey`.
2. Copy this skeleton into the repo (create files & folders).
3. Clone locally, `git checkout -b feature/week1/blinky`, follow Day1–Day7 tasks, push branch, open PR, merge.

---

## 15) Resources & links

* PlatformIO docs: [https://platformio.org](https://platformio.org)
* ESP-IDF docs: [https://docs.espressif.com](https://docs.espressif.com)
* FreeRTOS docs: [https://www.freertos.org](https://www.freertos.org)
* MQTT basics: HiveMQ tutorials

---

## 16) Next steps I can do for you (pick any)

* A. Generate the actual repo files and give a ZIP you can push to GitHub.
* B. Create a GitHub Actions `platformio.yml` CI file to auto-build on PRs.
* C. Auto-generate the first week's `main.cpp` + README filled with your email/name and ready commit messages.

Tell me which (A/B/C) you want me to do next and I'll prepare it for you.
