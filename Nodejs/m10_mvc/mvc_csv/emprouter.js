const express = require('express');
const router = express.Router();
const empcontroller = require('./empcontroller');

router.get('/queryall', empcontroller.queryall);
router.get('/queryone:empno', empcontroller.queryone);

module.exports = router;