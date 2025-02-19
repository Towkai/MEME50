const port=8181;
const http = require('http');
http.createServer((req, res) => {
    res.setHeader('content-type', 'text/html; charset=utf-8'); //如果沒有charset，中文會有亂碼
    if (req.method === 'POST')
    {
        let body = '';
        req.on('data', chunk => {           //req.on註冊事件
            console.log(`body: ${chunk}`);
            body += chunk.toString();       //chunk是Buffer物件，轉成字串存在body
        });
        req.on('end', () => {               //處理完資料觸發end事件
            let params = new URLSearchParams(body);
            let username = params.get('username');
            let age = params.get('age');
            let message = `${username}你好，今年${age}歲`;
            let html = `<html><body><h3>${message}</h3></body></html>`;
            res.end(html);
        })
    }
    else
        res.end('undefine');
}).listen(port, () => console.log(`Server running at http://localhost:${port}`));