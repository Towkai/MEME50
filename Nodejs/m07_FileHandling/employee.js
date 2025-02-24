const port = 8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
const fs = require('fs');
const readline = require('readline');
const csv2json = require('convert-csv-to-json');

function lineReader(file)
{
    let inputStream = fs.createReadStream(file);
    return readline.createInterface({ input: inputStream });
}

app.use((req, res, next) => {
    res.setHeader('content-type', 'text/html; charset=utf-8'); //如果沒有charset，中文會有亂碼
    next();
})
app.get('/read', (req, res) => {
    let lr = lineReader('employee.csv');
    let data = '';
    lr.on('line', line => {
        console.log(line);
        data += line+"<br>";
    });
    lr.on('close', () => {
        res.send(data);
    })
});
app.get('/readline', (req, res) => {
    let lr = lineReader('employee.csv');
    let fields, json = [];
    let first = true;
    lr.on('line', line => {
        let obj = {};
        if (first) {
            fields = line.split(',');
            first = false;
        }
        else {
            let data = line.split(',');
            for (let i = 0; i < data.length; i++)
                obj[fields[i]] = data[i];
            json.push(obj);
        }
    });
    lineReader.on('close', () => {
        console.log(json);
        res.send(json);
    })
})

app.get('/comma', (req, res) => {   //以逗號分隔
    csv2json.fieldDelimiter(',').generateJsonFileFromCsv('employee.csv', 'employee.json');
    let json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');
    console.log(json);
    res.send(json);
});

app.get('/semicolon', (req, res) => {   //以分號分隔
    csv2json.generateJsonFileFromCsv('employee copy.csv', 'employee copy.json');
    let json = csv2json.getJsonFromCsv('employee copy.csv');
    console.log(json);
    res.send(json);
});