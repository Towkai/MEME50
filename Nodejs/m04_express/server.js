//router
const port=8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

//gobal的middleware
app.use(express.urlencoded({extended:true}));   //for post method，解析資料並存在req.body
app.use((req, res, next) => {
    res.setHeader('content-type', 'text/html; charset=utf-8'); //如果沒有charset，中文會有亂碼
    next();
})
//特定route的middleware
//app.all，所有請求都會執行
app.get('/passOne', (req, res) => {
    let message = 'Hello ' + req.query['username'];
    let html = `<html><body><h3>${message}</h3></body></html>`;
    res.end(html);
});

app.post('/passMany', (req, res) => {
    let {username, age} = req.body;
    let message = `${username}你好，今年${age}歲`;
    let html = `<html><body><h3>${message}</h3></body></html>`;
    res.end(html);
});