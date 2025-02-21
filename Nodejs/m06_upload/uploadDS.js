const port = 8181;
const express = require('express');
const app = express();
const multer = require('multer');
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
const storage = multer.diskStorage({
    destination: function (req, file, callback) {
        callback(null, './public/img');
    },
    filename: function (req, file, callback) {
        callback(null, `_${Date.now()}_${file.originalname}`);
    }
});

const upload = multer({storage: storage});

app.post('/one', upload.single('file'), (req, res) => res.end('upload succcess'));
app.post('/multi', upload.array('file'), (req, res) => res.end('upload succcess'));
