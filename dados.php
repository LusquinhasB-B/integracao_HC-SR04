<!DOCTYPE html>
<html lang="br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="refresh" content="5">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
</body>
</html>

<?php

    $servername = "localhost";
    $username = "root";
    $password = ""; # É o padrão do xampp
    $dbname = "sensor_db";
    
    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->connect_error) {
        die("Conexao falhou: " . $conn->connect_error);
    }
    $sql = "SELECT * FROM leituras ORDER BY data_hora DESC";
    $result = $conn->query($sql);
    ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body { font-family: Arial; padding: 20px; background: #f2f2f2; }
        table { border-collapse: collapse; width: 100%; background: white; }
        th, td { padding: 10px; border: 1px solid #ccc; text-align: center; }
        th { background-color: #1E149B; color: white; }
    </style>
</head>
<body>
    <h2>Leituras do Sensor Ultrassônico</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Distância (cm)</th>
            <th>Data/Hora</th>
        </tr>
        <?php if ($result->num_rows > 0): ?>
            <?php while($row = $result->fetch_assoc()):?>
                <tr>
                    <td><?= $row["id"] ?></td>
                    <td><?= $row["distancia"] ?></td>
                    <td><?= $row["data_hora"] ?></td>
                </tr>
            <?php endwhile; ?>
        <?php else: ?>
            <tr> <td colspan="3">Nenhuma leitura encontradad</td></tr>
        <?php endif; ?>

    </table>
</body>
</html> 
<?php $conn->close(); ?>