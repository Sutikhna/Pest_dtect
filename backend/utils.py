def preprocess_input(data):
    """
    Preprocess sensor input for the model.
    Extend this function as you add more sensors.
    """
    temp = data.get('temperature', 0)
    humidity = data.get('humidity', 0)
    vibration = data.get('vibration', 0)
    motion = data.get('motion', 0)
    return [temp, humidity, vibration, motion]
