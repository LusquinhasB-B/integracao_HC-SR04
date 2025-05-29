import mysql.connector

conexao = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="sensor_db"
)
cursor = conexao.cursor()

def listar_dados():
    sql = "SELECT * FROM leituras;"
    cursor.execute(sql)
    return cursor.fetchall()

