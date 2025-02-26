const port=8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.set('view engine', 'ejs');

var router = require('./main_router');
app.use(express.urlencoded({extended: true}));
app.use('/nodejs_homework', router);
// app.post('/nodejs_homework/insert', (req, res) => {
//     console.log(req.body);
//     res.send("");
// });
