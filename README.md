# labead_diodo
Experimento de caracterização de diodo com Arduino Uno, com montagem de voltímetro e fonte de tensão.

## Requisitos

- Arduino IDE

- Computador com Sistema Operacional Windows

- Python 3

- Bibliotecas pyserial, flask

## Como usar

- Realizar montagem em protoboard ou placa para a fonte de tensão para caracterização de diodo (esquemáticos construídos com ferramenta de código aberto Fritzing <https://fritzing.org/>)

- Instalar Arduino IDE, Python 3 e bilbiotecas pyserial e flask em computador Windows

- Carregar o script no Arduino Uno usando a Arduino IDE (código na pasta UNOfonte_200920a)

- Substituir a porta USB na linha "ser = serial.Serial('COM7', baudrate=115200, timeout=10)" do arquivo app.py

- Executar o app.py com o Python 3, e abrir o navegador (e.g. Google Chrome) no endereço "http://127.0.0.1/"
