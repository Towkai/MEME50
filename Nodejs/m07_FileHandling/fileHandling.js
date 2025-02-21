const port = 8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
const fs = require('fs');

app.use((req, res, next) =>
{
    res.setHeader('Content-Type', 'text/html; charset=UTF-8');
    next();
});

app.get('/read', (req, res) => {
    fs.readFile('simple.html', (err, data) => {
        if (err) throw err;
        res.end(data);
    });
});

app.get('/write', (req, res) => {
    fs.writeFile('greet.txt', 'Hellow World!', (err, data) => {
        if (err) throw err;
        console.log('Saved!');
    });
   
    fs.appendFile('greet.txt', '\nHave a good time', (err, data) => {
        if (err) throw err;
        console.log('Appended!');
    });
    res.end('Saved!');
});