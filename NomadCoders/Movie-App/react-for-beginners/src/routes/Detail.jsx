import React, { useEffect } from "react";
import { useParams } from "react-router-dom";

function Detail() {
    // 매개변수 받기
    const {id} = useParams();
    const [loading, setLoading] = React.useState(true);
    const [movie, setMovie] = React.useState("");
    const getMovie = async () => {
        const json = await (
            await fetch(`https://yts.mx/api/v2/movie_details.json?movie_id=${id}`))
            .json();
        console.log(json);
        setMovie(json.data.movie);
        setLoading(false);
    }
    
    useEffect(() => {
        getMovie();
    }, []);

    return <div>{loading ? <h1>Loading...</h1> :
        <div>
            <img src={movie.medium_cover_image} alt="image"/>
            <h1>{movie.title} ({movie.year})</h1> 
            <h2>rating : {movie.rating}</h2>
            <h3>Download : {movie.download_count}</h3>
            <ul>
                {movie.genres.map(g => (
                <li key = {g}>{g}</li>
                ))}
            </ul>


        </div>
    }
    </div>;
}

export default Detail;