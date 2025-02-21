//router
const port=8181;
const express = require('express');
const cookieParser = require('cookie-parser');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.use(cookieParser());

app.get('/set', (req, res) => {
    res.cookie('name', 'kai', {maxAge: 6e5});
    res.cookie('gender', 'male', {maxAge: 6e5});
    res.end('set');
});

app.get('/get', (req, res) => {
    console.log(req.cookies);
    res.end(`Hello ${req.cookies['name']}`);
});