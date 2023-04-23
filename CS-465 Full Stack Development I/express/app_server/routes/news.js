const express = require('express');
const router = express.Router();

const news_controller = require('../controllers/news');

router.get('/', news_controller.news);

module.exports = router;