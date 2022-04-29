using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class roomParameters : MonoBehaviour
{
    NavMeshSurface2d NavMesh;
    public unit[] unitsInRoom;
    int x = 0, enemy_waves = 0;
    void Start()
    {
        NavMesh = GameObject.Find("NavMesh Surface").GetComponent<NavMeshSurface2d>();
    }
    public void activation()
    {
        transform.Find("Gates_0").gameObject.SetActive(true);
        transform.Find("Gates_1").gameObject.SetActive(true);
        NavMesh.BuildNavMesh();
        for(int i = 0; i<unitsInRoom.Length; i++)
        {
            unitsInRoom[i].activation();
        }
        transform.Find("Floor").GetComponent<Collider2D>().enabled = false;
    }
    public void someUnitIsZdoh()
    {
        x++;
        if (x == unitsInRoom.Length)
        {
            unitsInRoom = new unit[0];
        }
    }
}
