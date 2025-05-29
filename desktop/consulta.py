import sys
from PyQt5.QtWidgets import *
from folder_controller.controller import obter_dados

varDadosController = obter_dados()

app = QApplication(sys.argv) 


#----------------------------Cria a janela e o titulo----------------#
janela = QWidget()
janela.setWindowTitle("Distância e horas registradas!")
janela.setGeometry(500, 100, 400, 500)
janela.setFixedSize(400, 500)

layout = QVBoxLayout()
janela.setLayout(layout)

tabela = QTableWidget(janela)
tabela.setColumnCount(3)
tabela.setHorizontalHeaderLabels(["ID", "Distância", "Data_hora"])
tabela.setStyleSheet("""
    QWidget {
        background-color: #e3f2fd;
        font-family: Arial, sans-serif;
        font-size: 14px;
        color: #333;
    }
    QLabel {
        font-weight: bold;
    }
    QLineEdit, QTableWidget {
        background-color: white;
        border: 1px solid #ccc;
        border-radius: 5px;
        padding: 4px;
    }
    QPushButton {
        background-color: #4CAF50;
        color: white;
        border-radius: 5px;
        padding: 6px;
        font-weight: bold;
        border: none;
    }
    QPushButton:hover {
        background-color: #45a049;
    }
    QPushButton#cancelar {
        background-color: #d9534f;
    }
    QPushButton#cancelar:hover {
        background-color: #c9302c;
    }

""")
tabela.setGeometry(0, 0, 360, 200)


def carregar_dados():
    tabela.clearContents()
    tabela.setRowCount(0)

    dadosDistancia= obter_dados()
    tabela.setRowCount(len(dadosDistancia))

    for row, dados in enumerate(dadosDistancia):
        tabela.setItem(row, 0, QTableWidgetItem(str(dados[0])))
        tabela.setItem(row, 1, QTableWidgetItem(str(dados[1])))
        tabela.setItem(row, 2, QTableWidgetItem(str(dados[2])))



textoAtualiza = QLabel("Atualizar os dados da tabela", janela)
botao_atualizar = QPushButton("Atualizar dados!", janela)
botao_atualizar.clicked.connect(carregar_dados) 
botao_atualizar.setGeometry(120, 140, 90, 30)

layout.addWidget(tabela)
layout.addWidget(textoAtualiza)
layout.addWidget(botao_atualizar)


janela.show()
sys.exit(app.exec_())
