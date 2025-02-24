const port = 8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
const csv2json = require('convert-csv-to-json');

var json = '';
app.use((req, res, next) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');
    next();
});

app.get('/employee/getAll', (req, res) => {
    res.send(json);
});

app.get('/employee/getone/:empno', (req, res) => {
    let empno = req.params["empno"];
    for (let i = 0; i < json.length; i++) {
        if (json[i].empno == empno) {
            emp = json[i];
            break;
        }
    }
    res.send(emp);
});