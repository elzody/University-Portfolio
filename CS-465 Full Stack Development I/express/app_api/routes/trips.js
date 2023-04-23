const express = require('express');
const router = express.Router();
const { expressjwt: jwt } = require("express-jwt");

// This line configures middleware that checks user credentials before executing the route
const auth = jwt({ secret: process.env.JWT_SECRET, algorithms: ["HS256"] });

const controller = require('../controllers/trips');

router.use(express.urlencoded({extended: true}));

router.get('/:tripCode?', controller.fetchTrips);

// Only put, post, and delete need to be protected here...
router.post('/', auth, controller.addTrip);
router.put('/:tripCode', auth, controller.updateTrip);
router.delete('/:tripCode', auth, controller.deleteTrip);

module.exports = router;