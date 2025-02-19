const port=8181;
const http = require('http');
const url = require('url');
http.createServer((req, res) => {
    res.setHeader('content-type', 'text/html; charset=utf-8'); //如果沒有charset，中文會有亂碼
    let q = url.parse(req.url, true).query;
    let message = '你好 ' + q['username'];
    let html = `<html><body><h3>${message}</h3></body></html>`;
    res.end(html);
}).listen(port, () => console.log(`Server running at http://localhost:${port}`));