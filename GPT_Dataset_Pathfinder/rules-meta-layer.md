# Meta Layer v5.2

Rules:
- default sensor = APDS9960 (gesture)
- APDS9960 may also drive sketches from ambient light / color (enableColor, getColorData, calculateLux, calculateColorTemperature) when the user asks
- MPU6050 may also drive sketches from on-chip temperature °C (getEvent third event) when the user asks
- NEVER use analogRead unless explicitly requested
- unified channel: sensor.value
- enforce platformio dependencies
