import React, { useEffect, useState } from "react";


function Coin() {
  const [loading , setLoading] =useState(true);
  const [coins, setCoins] = React.useState([]);
  const [money, setMoney] = React.useState(0);
  const [coin, setCoin] = React.useState("");

  const regex = /[^.0-9]/g;
  
  const onChangeMoney = (event) => {
    setMoney(event.target.value)
  }

  const onChange = (event) => {
    setCoin(event.target.value);
  }

  useEffect(() => {
    fetch("https://api.coinpaprika.com/v1/tickers?limit=200")
      .then((response) => response.json())
      .then((json) => {
        setCoins(json);
        setLoading(false);
      });
  }, []);

  
  return (
    <div>
      <h1>The Coins! {loading ? "" : coins.length}</h1>
      {loading ? <strong>Loading...</strong> : null}
      <input type = "number" placeholder="please enter money (USD)" onChange={onChangeMoney}/>
      
      <select onChange={onChange}>
        {coins.map((coin) => {
          return (
            <option key = {coin.id}>
              {coin.name} ({coin.symbol}) : {coin.quotes.USD.price} USD
            </option>
          );
        })}
      </select>
      <hr />
      You can buy {money / coin.replace(regex, "")} coins
    </div>
  );
}

export default Coin;
