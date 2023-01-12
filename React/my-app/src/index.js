import React from 'react';
import ReactDOM from 'react-dom/client';
import Accommodate from './chapter_07/Accmmodate';
import Counter from './chapter_07/Example';
import ConfirmButton from './chapter_08/ConfirmButton';
import Toggle from './chapter_08/example1';
import LandingPage from './chapter_09/LandingPage';

import './index.css';

import reportWebVitals from './reportWebVitals';

const root = ReactDOM.createRoot(document.getElementById('root'));
/*
setInterval(() => {
    root.render(
    <React.StrictMode>
      <Clock />
    </React.StrictMode>
  );
}, 1000);
*/

root.render(
  <React.StrictMode>
    <LandingPage />
  </React.StrictMode>
); 
// React 18 부터 이전과 다르게 ReactDom.render를 못씀
// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
