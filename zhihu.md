# zhihu
### short guides for Rookie
* [VScode relating](#VScode-relating)





## VScode relating:
1 * [Switching claude settings to other api service platforms](#vscode.claude.api)

vscode.claude.api.md
# Configure Claude Code via settings.json

### This guide helps you set up custom API endpoints and model mappings for Claude Code (the terminal-based agent). The configuration file is a standard JSON file located in your home directory.

---
## Step 1: Locate or Create the File

The file path depends on your operating system:

Linux/ macOS :    
```
~/.claude/settings.json
```
Windows   :
```
%USERPROFILE%\.claude\settings.json
```
>[!IMPORTANT]
>If the file does not exist, create it manually; Maker sure it is "settings" not "setting";
---
## Step 2: Edit with Your Configuration

1. Open the file in any text editor and paste the following template. Replace the placeholder values with your actual provider information.
```text
{
"includeCoAuthoredBy": false,
 "env": {

  "ANTHROPIC_BASE_URL": "https://your-provider-api.example.com",

  "ANTHROPIC_AUTH_TOKEN": "sk-your-api-key-here",

  "ANTHROPIC_DEFAULT_OPUS_MODEL": "deepseek-v4-flash[1m]",
  "ANTHROPIC_DEFAULT_SONNET_MODEL": "deepseek-v4-flash[1m]",
  "ANTHROPIC_DEFAULT_HAIKU_MODEL": "deepseek-v4-flash[1m]"
 }
}
```

2. Switch to VScode, Using Ctrl+Shift+P to open Preference: Open User Settings: (JSON)
3. Add ~ underneath the  "claudeCode.preferredLocation": "panel"

```
,
  "claudeCode.environmentVariables": [
{ "name": "ANTHROPIC_BASE_URL", "value": "https://xxxx" },
{ "name": "ANTHROPIC_AUTH_TOKEN", "value": "xxxx" }

  ],
```
> [!TIP]
> 
> 1. includeCoAuthoredBy Set to false to omit "Co-Authored-By: Claude" from commit messages.
> 
> 2. ANTHROPIC_BASE_URL The base URL of your API provider (not DeepSeek's official endpoint).
> Must be compatible with Anthropic's message format.
> 
> 4. ANTHROPIC_AUTH_TOKEN Your API key from the provider.
> 
> 5. Three model variables Model identifiers for different complexity tiers.
>You can use the same model name for all three to avoid "model not found" errors.


>[!IMPORTANT]
>- ANTHROPIC_BASE_URL must point to a provider/middleware that speaks the Anthropic-compatible protocol. Directly using DeepSeek's own URL will not work because the request formats differ.
>- Setting all three model fields to the same value is safe and prevents missing-model errors.


---
## Step 3: Save, Restart, and Verify

1\. Save the file.

2\. Close and reopen VS Code (or restart the Claude Code terminal session).

3\. Run a simple conversation with Claude Code, e.g., "List files in current directory" or "Create a small Python script."

4\. If everything works, Claude will respond using your configured backend.


> [!TIP]
> To double-check which settings are loaded, type inside Claude Code:
> /status
> Look for the line starting with Setting sources – it should list your user-level config file.


	
> [!NOTE]
>• Variable names and model identifiers may change over time. This guide was written in September 2026. Always refer to your provider's latest documentation if something fails.
>• The \~/.claude/settings.json file applies globally to all projects on your machine. For per‑project overrides, place a .claude/settings.json inside the project root (not tracked by Git by default) or .claude/settings.local.json (local only).

Happy coding!✅

