SELECT * FROM leituras;


CREATE TABLE leituras(
	id INT AUTO_INCREMENT PRIMARY KEY,
    distancia FLOAT NOT NULL,
    data_hora TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO leituras(distancia) VALUES(45.0);