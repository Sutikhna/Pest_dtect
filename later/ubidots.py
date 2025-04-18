import requests

UBIDOTS_TOKEN = "YOUR_UBIDOTS_TOKEN"
DEVICE_LABEL = "esp32_pest_detector"

def send_to_ubidots(sensor_data, prediction):
    url = f"https://industrial.api.ubidots.com/api/v1.6/devices/{DEVICE_LABEL}/"
    headers = {"X-Auth-Token": UBIDOTS_TOKEN, "Content-Type": "application/json"}
    payload = {
        "temperature": sensor_data.get("temperature"),
        "humidity": sensor_data.get("humidity"),
        "vibration": sensor_data.get("vibration"),
        "motion": sensor_data.get("motion"),
        "pest_detected": int(prediction)
    }
    try:
        requests.post(url, json=payload, headers=headers, timeout=5)
    except Exception as e:
        print(f"Ubidots upload failed: {e}")
