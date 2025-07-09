-- ~/.hammerspoon/init.lua
local currentLayer = "BASE"
local consoleTask = nil

function showLayerToast(layer)
    print("showLayerToast called with: " .. layer)
    
    if layer ~= currentLayer then
        currentLayer = layer
        print("Layer changed to: " .. layer)
        
        -- Modern glass effect toast
        hs.alert.show("⌨️ " .. layer, {
            textColor = {white = 1, alpha = 0.95},
            fillColor = getLayerColor(layer),
            strokeColor = {white = 1, alpha = 0.3},
            strokeWidth = 1.5,
            radius = 18,
            textSize = 20,
            textFont = "Menlo",
            fadeInDuration = 0.3,
            fadeOutDuration = 0.8,
            atScreenEdge = 0,
            padding = 25
        }, 2)
    else
        print("Layer unchanged: " .. layer)
    end
end

function getLayerColor(layer)
    -- Modern glass colors with transparency and blur effect
    local colors = {
        BASE = {red = 0.15, green = 0.15, blue = 0.15, alpha = 0.85},      -- Dark glass
        NUMS = {red = 0.9, green = 0.5, blue = 0.1, alpha = 0.85},         -- Orange glass
        MEDIA = {red = 0.85, green = 0.2, blue = 0.2, alpha = 0.85},       -- Red glass
        SYSTEM = {red = 0.1, green = 0.4, blue = 0.9, alpha = 0.85}        -- Blue glass
    }
    return colors[layer] or {red = 0.3, green = 0.3, blue = 0.3, alpha = 0.85}
end

function startQMKConsoleMonitoring()
    print("=== Starting QMK Console Monitoring ===")
    
    if consoleTask then
        consoleTask:terminate()
        consoleTask = nil
    end
    
    consoleTask = hs.task.new("/opt/homebrew/bin/qmk", nil, function(exitCode, stdOut, stdErr)
        print("Console callback - Exit code: " .. exitCode)
        if stdOut and stdOut ~= "" then
            print("Console StdOut: " .. stdOut)
            for line in stdOut:gmatch("[^\r\n]+") do
                print("Processing line: " .. line)
                if line:match("LAYER:") then
                    local layer = line:match("LAYER:(%w+)")
                    if layer then
                        print("Found layer: " .. layer)
                        showLayerToast(layer)
                    end
                end
            end
        end
        if stdErr and stdErr ~= "" then
            print("Console StdErr: " .. stdErr)
        end
    end, {"console"})
    
    consoleTask:setStreamingCallback(function(task, stdOut, stdErr)
        if stdOut and stdOut ~= "" then
            print("Streaming StdOut: " .. stdOut)
            for line in stdOut:gmatch("[^\r\n]+") do
                print("Streaming line: " .. line)
                if line:match("LAYER:") then
                    local layer = line:match("LAYER:(%w+)")
                    if layer then
                        print("Streaming found layer: " .. layer)
                        showLayerToast(layer)
                    end
                end
            end
        end
        if stdErr and stdErr ~= "" then
            print("Streaming StdErr: " .. stdErr)
        end
        return true
    end)
    
    local success = consoleTask:start()
    print("Console task started: " .. tostring(success))
    
    if success then
        -- Modern startup notification
        hs.alert.show("🎯 QMK Layer Monitor Active", {
            textColor = {white = 1, alpha = 0.95},
            fillColor = {red = 0.1, green = 0.7, blue = 0.3, alpha = 0.85},
            strokeColor = {white = 1, alpha = 0.3},
            strokeWidth = 1.5,
            radius = 18,
            textSize = 18,
            textFont = "SF Pro Display",
            fadeInDuration = 0.3,
            fadeOutDuration = 0.8,
            atScreenEdge = 0,
            padding = 25
        }, 2)
    else
        hs.alert.show("❌ Failed to start QMK Console", {
            textColor = {white = 1, alpha = 0.95},
            fillColor = {red = 0.8, green = 0.2, blue = 0.2, alpha = 0.85},
            strokeColor = {white = 1, alpha = 0.3},
            strokeWidth = 1.5,
            radius = 18,
            textSize = 18,
            textFont = "SF Pro Display",
            fadeInDuration = 0.3,
            fadeOutDuration = 0.8,
            atScreenEdge = 0,
            padding = 25
        }, 3)
    end
end

-- Test functions with modern styling
hs.hotkey.bind({"cmd", "alt", "ctrl"}, "T", function()
    print("Manual toast test")
    showLayerToast("TEST")
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "1", function()
    print("Simulating BASE layer")
    showLayerToast("BASE")
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "2", function()
    print("Simulating NUMS layer")
    showLayerToast("NUMS")
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "3", function()
    print("Simulating MEDIA layer")
    showLayerToast("MEDIA")
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "4", function()
    print("Simulating SYSTEM layer")
    showLayerToast("SYSTEM")
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "R", function()
    print("Restarting QMK console monitoring")
    startQMKConsoleMonitoring()
end)

hs.hotkey.bind({"cmd", "alt", "ctrl"}, "S", function()
    if consoleTask then
        consoleTask:terminate()
        print("QMK Console stopped")
        hs.alert.show("⏹️ QMK Console Stopped", {
            textColor = {white = 1, alpha = 0.95},
            fillColor = {red = 0.6, green = 0.6, blue = 0.6, alpha = 0.85},
            strokeColor = {white = 1, alpha = 0.3},
            strokeWidth = 1.5,
            radius = 18,
            textSize = 18,
            textFont = "SF Pro Display",
            fadeInDuration = 0.3,
            fadeOutDuration = 0.8,
            atScreenEdge = 0,
            padding = 25
        }, 1)
    end
end)

-- Start monitoring
startQMKConsoleMonitoring()

-- Clean up on shutdown
hs.shutdownCallback = function()
    if consoleTask then
        consoleTask:terminate()
    end
end