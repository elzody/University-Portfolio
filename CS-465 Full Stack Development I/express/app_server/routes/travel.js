const express = require('express');
const router = express.Router();

const travel_controller = require('../controllers/travel');

router.get('/', travel_controller.travel);

module.exports = router;