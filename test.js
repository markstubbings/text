function calculateDaysBetweenDates(begin, end) {    
    return Math.round((end - begin) / (1000 * 60 * 60 * 24));
}
// express server on port 3000
app.get('/days', (req, res) => {
    const begin = new Date(req.query.begin);
    const end = new Date(req.query.end);
    res.send({days: calculateDaysBetweenDates(begin, end)});
});
app.listen(3000, () => console.log('Server running on port 3000'));
