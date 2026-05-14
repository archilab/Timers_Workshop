# Cline — Pathfinder / Folkwang ESP32 workshop

Self-contained bundle for [Cline](https://cline.bot): **`CLINE.md`**, **`.cline/rules/*.md`** (YAML `alwaysApply`, including **`07-generator-contract.md`** — former system prompt), and **`.context/`** with library API docs, samples, template, and routing — same layout as **`claude_pathfinder/`** (`.cline/rules` ↔ `.claude/rules`).

## Contents

| Path | Purpose |
|------|---------|
| `CLINE.md` | Project instructions and source priority (mirror of `claude_pathfinder/CLAUDE.md`) |
| `.cline/rules/00–07-*.md` | Cline rules + **`07-generator-contract.md`** (FolkwangESP-GPT identity & output contract) |
| **`.context/`** | `context-*.md`, `rules-meta-layer.md`, `rules-validation.md`, `sample-*.cpp`, `template-platformio.ini`, `config-routing.json` |

Markdown links in **`.cline/rules/*.md`** use **`../../.context/...`** (two levels up from `.cline/rules/` to `cline_pathfinder/`).

## Install

Keep the full **`cline_pathfinder/`** tree in the repository.

1. Copy rule files to the workspace **`.clinerules`** folder (Cline convention):

   ```bash
   mkdir -p .clinerules
   cp cline_pathfinder/.cline/rules/*.md .clinerules/
   ```

2. Optional: add **`CLINE.md`** context by opening or `@`-including `cline_pathfinder/CLINE.md` in your workflow, or paste its priority block into Cline custom instructions.

Restart VS Code or reload Cline; enable rules in the Cline **Rules** panel.

### Windows (PowerShell)

```powershell
New-Item -ItemType Directory -Force -Path .clinerules | Out-Null
Copy-Item -Force cline_pathfinder\.cline\rules\*.md .clinerules\
```

## Parity with `claude_pathfinder/`

| Cline | Claude |
|-------|--------|
| `CLINE.md` | `CLAUDE.md` |
| `.cline/rules/*.md` | `.claude/rules/*.md` |
| `.context/` | `.context/` |

## Updating this bundle

When files change in **`GPT_Dataset_Pathfinder/`** or **`claude_pathfinder/`**, re-copy **`.context/`** from `claude_pathfinder/` (or from the dataset), copy **`07-generator-contract.md`** from **`claude_pathfinder/.claude/rules/`** if the contract changed, then adjust other **`.cline/rules/`** only if workshop rules diverge.
