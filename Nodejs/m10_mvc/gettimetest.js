const port=8181;
const express = require('express');
const app = express();
const time = require('./gettime.js');
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.use((req, res, next) => {
    res.setHeader('content-type', 'text/html; charset=utf-8'); //如果沒有charset，中文會有亂碼
    next();
});

app.get('/', (req, res) => {
    res.send("Current date and time: " + time.now());
});