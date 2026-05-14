# Claude Code — Timers Workshop / Folkwang

Self-contained bundle for [Claude Code](https://code.claude.com/docs): **`CLAUDE.md`**, **`.claude/rules/*.md`** (including **`07-generator-contract.md`** for **Folkwang_Timers**), **library API context** (`context-library-*.md`), **example sketches** (`sample-*.cpp`), and **`template-platformio.ini`** — paths stay inside **`claude_pathfinder/`**.

## Contents

| Path | Role |
|------|------|
| `CLAUDE.md` | Entry point for the agent |
| `.claude/rules/00–07-*.md` | Rules + **`03-i2c-time-display.md`** (I²C / RTC / OLED / VL53L0X) |
| `.context/context-library-*.md` | Full API surface for allowed `lib_deps` |
| `.context/sample-*.cpp` | Patterns only |
| `.context/template-platformio.ini` | Nano `lib_deps` template |

## Sync from repo

When **`Dataset_Timers/`** changes, copy affected files into **`.context/`** and update **`07-generator-contract.md`** if the product contract changed.

**Workshop GPT:** [Folkwang_Timers (ChatGPT)](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)
