from flask import Flask, request
import mysql.connector

app = Flask(__name__)

conn = mysql.connector.connec(
    host="localhost",
    user="root",
    password="",
    database="sensor_db"
)

@app.route('/dados', methods=['GET'])
def receber():
    distancia = request.args.get('distancia')

    if distancia:

        cursor = conn.cursor()
        cursor.execute("INSERT INTO leituras (distancia) VALUES (%s)", (distancia,))
        conn.commit()
        return "Dados recebidos com sucesso!", 200
    else:
        return "ERRO! Distância não recebida", 400
    
if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000)    
