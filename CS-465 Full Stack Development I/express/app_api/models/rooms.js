const mongoose = require('mongoose');

const roomsSchema = mongoose.Schema({
    code: {type: String, required: true, index: true},
    name: {type: String, required: true, index: true},
    image: {type: String, required: true},
    description: {type: String, required: true},
    rate: {type: Number, required: true}
});

module.exports = {
    rooms: mongoose.model('rooms', roomsSchema)
}