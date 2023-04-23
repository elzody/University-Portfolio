const express = require('express');
const router = express.Router();

const rooms_controller = require('../controllers/rooms');

router.get('/', rooms_controller.rooms);

module.exports = router;