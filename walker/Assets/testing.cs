using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testing : MonoBehaviour
{
    Vector2Int currentPosition = new Vector2Int(2, 2);
    private int[,] field = new int[5, 5];
    private int room_count;
    [SerializeField] GameObject square;
    [SerializeField] GameObject roomPrefab, portal, top_down_corridor, right_left_corridor;
   
    void Start()
    {
        field[2, 2] = 1;
        print("Defauld field is reserved");
        GameObject defaulted = Instantiate(square, new Vector3(0,0,0), Quaternion.identity);
        defaulted.GetComponent<SpriteRenderer>().color = Color.red;
        room_count = Random.Range(4, 8);
        print("Ты можешь сделать " + (room_count + 1) + " комнат");
        print(Vector2.Distance(new Vector2(4, 2), new Vector2(2, 2)));
        //StartCoroutine("coming");
        coming();
        //zalupa();
    }
    public void coming()
    {
        Vector2Int spawnCoordinates = new Vector2Int(0, 0);
        GameObject xd = Instantiate(roomPrefab, transform);
        xd.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y);
        while (room_count > 0)
        {
            int direction = Random.Range(0, 4);
            try
            {
                switch (direction)
                {
                    case 0:
                        if (field[currentPosition.x, currentPosition.y + 1] == 0)
                        {
                            field[currentPosition.x, currentPosition.y + 1] = 1;
                            currentPosition += new Vector2Int(0, 1);
                            spawnCoordinates += new Vector2Int(0, 41);
                            GameObject maked_room = Instantiate(roomPrefab, transform);
                            maked_room.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y);
                            GameObject corridor_ = Instantiate(top_down_corridor, transform);
                            corridor_.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y - 20.5f);
                            if (room_count == 1) Instantiate(portal, new Vector3(spawnCoordinates.x, spawnCoordinates.y), Quaternion.identity);
                            room_count--;
                        }
                        else
                        {
                            spawnCoordinates += new Vector2Int(0, 41);
                            currentPosition += new Vector2Int(0, 1);
                        }
                        break;
                    case 1:
                        if (field[currentPosition.x + 1, currentPosition.y] == 0)
                        {
                            field[currentPosition.x + 1, currentPosition.y] = 1;
                            currentPosition += new Vector2Int(1, 0);
                            spawnCoordinates += new Vector2Int(41, 0);
                            GameObject maked_room = Instantiate(roomPrefab, transform);
                            maked_room.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y);
                            GameObject corridor_ = Instantiate(right_left_corridor, transform);
                            corridor_.transform.position = new Vector3(spawnCoordinates.x - 20.5f, spawnCoordinates.y);
                            if (room_count == 1) Instantiate(portal, new Vector3(spawnCoordinates.x, spawnCoordinates.y), Quaternion.identity);
                            room_count--;
                        }
                        else
                        {
                            spawnCoordinates += new Vector2Int(41, 0);
                            currentPosition += new Vector2Int(1, 0);
                        }
                        break;
                    case 2:
                        if (field[currentPosition.x, currentPosition.y - 1] == 0)
                        {
                            field[currentPosition.x, currentPosition.y - 1] = 1;
                            currentPosition += new Vector2Int(0, -1);
                            spawnCoordinates += new Vector2Int(0, -41);
                            GameObject maked_room = Instantiate(roomPrefab, transform);
                            maked_room.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y);
                            GameObject corridor_ = Instantiate(top_down_corridor, transform);
                            corridor_.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y + 20.5f);
                            if (room_count == 1) Instantiate(portal, new Vector3(spawnCoordinates.x, spawnCoordinates.y), Quaternion.identity);
                            room_count--;
                        }
                        else
                        {
                            spawnCoordinates += new Vector2Int(0, -41);
                            currentPosition += new Vector2Int(0, -1);
                        }
                        break;
                    case 3:
                        if (field[currentPosition.x - 1, currentPosition.y] == 0)
                        {
                            field[currentPosition.x - 1, currentPosition.y] = 1;
                            currentPosition += new Vector2Int(-1, 0);
                            spawnCoordinates += new Vector2Int(-41, 0);
                            GameObject maked_room = Instantiate(roomPrefab, transform);
                            maked_room.transform.position = new Vector3(spawnCoordinates.x, spawnCoordinates.y);
                            GameObject corridor_ = Instantiate(right_left_corridor, transform);
                            corridor_.transform.position = new Vector3(spawnCoordinates.x + 20.5f, spawnCoordinates.y);
                            if (room_count == 1) Instantiate(portal, new Vector3(spawnCoordinates.x, spawnCoordinates.y), Quaternion.identity);
                            room_count--;
                        }
                        else
                        {
                            spawnCoordinates += new Vector2Int(-41, 0);
                            currentPosition += new Vector2Int(-1, 0);
                        }
                        break;

                }
            }
            catch (System.IndexOutOfRangeException)
            {
                currentPosition = new Vector2Int(2, 2);
                print("Ты вышел за границу");
                spawnCoordinates = new Vector2Int(0, 0);
                continue;
            }
        }
    }
}
//пошла пизда по кочкам 2