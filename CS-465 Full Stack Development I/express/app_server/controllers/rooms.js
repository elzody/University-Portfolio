const mongoose = require('mongoose');
const rooms_model = mongoose.model('rooms');

async function rooms(req, res) {
    res.render('rooms', { 
        title: 'Travlr Getaways', 
        myRooms: await rooms_model.find({}),
        roomSelected: req.path == '/rooms'
    });
};

module.exports = { rooms };