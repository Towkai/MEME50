//router
const port=8181;
const express = require('express');
const session = require('express-session');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.use(session({
        secret: 'login', // require
        name: 'userId',
        saveUninitialized: false,
        resave: true
    })
);

app.get('/', (req, res) => {
    req.session["user"] = 'kai';
    req.session["pwd"] = 'passw0rd';
    console.log(req.session);
    console.log(req.sessionID);
    res.end('Hellow ' + req.session.user);
});