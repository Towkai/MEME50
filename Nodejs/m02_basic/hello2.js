const port=8181;
const http = require('http');
http.createServer((req, res) => {
    res.writeHead(200, {'content-type':'text/html'});
    res.end('Hello world again!!');
}).listen(port, () => console.log(`Server running at http://localhost:${port}`));