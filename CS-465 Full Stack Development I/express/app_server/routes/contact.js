const express = require('express');
const router = express.Router();

const contact_controller = require('../controllers/contact');

router.get('/', contact_controller.contact);

module.exports = router;