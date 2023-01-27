import PropTypes from "prop-types";
import { Link } from "react-router-dom";

function Movie({coverImg, title, summary, year, genres, id}) {
    return (
    <div>
        <img src = {coverImg} alt = {title}/>
        <h2>
            <Link to={`/movie/${id}`}>{title}</Link> ({year})
        </h2>
        <p>{summary}</p>
        <ul>
            {genres.map(g => (
                <li key = {g}>{g}</li>
            ))}
        </ul>
    </div>);
}

Movie.propTypes = {
    coverImg: PropTypes.string.isRequired,
    title : PropTypes.string.isRequired,
    summary : PropTypes.string.isRequired,

}

export default Movie;