const mongoose = require('mongoose');
const rooms = mongoose.model('rooms');

const fetchRooms = async (req, res) => {
    if (req.params.roomCode) {
        try {
            res.json(await rooms.findOne({'code': req.params.roomCode}));
        } catch (e) {
            res.status(404).send(`No room found for code ${req.params.roomCode}`);
        }

        return;
    }

    res.json(await rooms.find({}));
}

module.exports = {
    fetchRooms
}