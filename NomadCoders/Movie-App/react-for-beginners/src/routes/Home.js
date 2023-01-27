import React, { useEffect, useState } from "react";
import Movie from "../components/Movie";

function Home() {
    const [loading, setLoading] = React.useState(true);
    const [movies, setMovies] = React.useState([]);
    const getMovies = async() => {
        const response = await fetch(`https://yts.mx/api/v2/list_movies.json?minimum_rating=9&sort_by=year`);
        const json = await response.json();
        setMovies(json.data.movies);
        setLoading(false);
    }
    useEffect(() => {
        getMovies();
    }, []);

    console.log(movies);
    return <div>
        <h1>Movie-App</h1>
        {loading ? <h1>Loading...</h1> : <div>{movies.map(movie => {
            return (<Movie
                key = {movie.id}
                id = {movie.id}
                coverImg={movie.medium_cover_image}
                title = {movie.title}
                summary = {movie.summary}
                genres = {movie.genres}
                year = {movie.year}
            
            />);
        })}</div>}
    </div>
}

export default Home;