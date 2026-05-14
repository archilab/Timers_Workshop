# Claude Code — Pathfinder / Folkwang ESP32 workshop

Self-contained bundle for [Claude Code](https://code.claude.com/docs): **`CLAUDE.md`**, **`.claude/rules/*.md`** (including **`07-generator-contract.md`** — former system prompt), **library API context** (`context-library-*.md`), **example sketches** (`sample-*.cpp`), PairLink context, and PlatformIO template — **all paths stay inside `claude_pathfinder/`** (no `../` to other folders).

## Contents (this directory)

| Path | Purpose |
|------|---------|
| `CLAUDE.md` | Short project instructions and source priority |
| `.claude/rules/00–07-*.md` | Agent rules + **`07-generator-contract.md`** (FolkwangESP-GPT identity & output contract) |
| **`.context/`** | Bundled workshop knowledge (see below) |

### `.context/` (library context, rules, samples, template, routing)

| Files | Purpose |
|--------|---------|
| `rules-meta-layer.md`, `rules-validation.md` | Short workshop rules |
| `context-pairlink.md` | PairLink API and networking |
| `context-library-index.md`, `context-library-*.md` | Offline library API reference |
| `context-example-scripts.md` | How samples relate to rules; suggested knowledge order |
| `template-platformio.ini`, `config-routing.json` | Env template and optional routing aliases |
| `sample-*.cpp` | Reference sketches (not normative) |

## Install in a project

Keep the **`claude_pathfinder/`** folder in your repository (or copy it wholesale). Rule files under `.claude/rules/` link into `claude_pathfinder/` using `../../` / `../../.context/` as needed.

1. Copy rules:

   ```bash
   mkdir -p .claude/rules
   cp claude_pathfinder/.claude/rules/*.md .claude/rules/
   ```

2. Expose instructions to Claude Code (pick one):

   - **A — Import from repo root `CLAUDE.md`:** add a line so the bundled instructions load (paths inside `claude_pathfinder/CLAUDE.md` stay valid):

     ```markdown
     @claude_pathfinder/CLAUDE.md
     ```

   - **B — Copy:** copy `claude_pathfinder/CLAUDE.md` to the repo root and merge with any existing `CLAUDE.md`, **or** duplicate the whole `claude_pathfinder` tree (same layout as here).

Start a new session or use `/memory` to verify what loaded.

### Windows (PowerShell)

```powershell
New-Item -ItemType Directory -Force -Path .claude\rules | Out-Null
Copy-Item -Force claude_pathfinder\.claude\rules\*.md .claude\rules\
```

## Updating this bundle

When you change the workshop files in the repository’s `GPT_Dataset_Pathfinder/` tree, re-copy the affected files into **`claude_pathfinder/.context/`**, then adjust **`CLAUDE.md`** or **`.claude/rules/`** (including **`07-generator-contract.md`**) if the generator contract changed.
