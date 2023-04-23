const express = require('express');
const router = express.Router();

const meals_controller = require('../controllers/meals');

router.get('/', meals_controller.meals);

module.exports = router;