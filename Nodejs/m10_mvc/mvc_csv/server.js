const port=8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.set('view engine', 'ejs');

var emprouter = require('./emprouter');
app.use('/employee', emprouter);