const port=8181;
const http = require('http');
http.createServer(function(req, res) {
    res.writeHead(200, {'content-type':'text/html'});
    res.end('Hello world!!');
}).listen(port);