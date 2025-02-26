const express = require('express');
const router = express.Router();
const index = require('./controller_index.js');
const insert = require('./controller_insert.js');
const insert_lr = require('./controller_insert_lr.js');
const search = require('./controller_search.js');

router.get('/', index.get);
router.get('/insert', insert.view_insert);
router.post('/insert', insert.feature_insert);
router.get('/insert_lr', insert_lr.view_insert);
router.post('/insert_lr', insert_lr.feature_insert);
router.get('/search', search.view_search);
router.post('/search', search.feature_search);


module.exports = router;