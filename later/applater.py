from flask import Flask, request, jsonify
import pickle
from utils import preprocess_input
from excel_writer import write_to_excel

app = Flask(__name__)

with open('pest_model.pkl', 'rb') as f:
    model = pickle.load(f)

@app.route('/predict', methods=['POST'])
def predict():
    data = request.json
    features = preprocess_input(data)
    prediction = model.predict([features])[0]
    write_to_excel(data, int(prediction))
    return jsonify({'prediction': int(prediction)})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

