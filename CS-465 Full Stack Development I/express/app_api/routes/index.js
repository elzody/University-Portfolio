const express = require('express');
const router = express.Router();

const trips_router = require('./trips');
const rooms_router = require('./rooms');
const auth_router = require('./authentication');

router.use('/trips', trips_router);
router.use('/rooms', rooms_router);
router.use('/auth', auth_router);

module.exports = router;