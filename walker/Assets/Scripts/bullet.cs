using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bullet : MonoBehaviour
{
    float bullet_speed;
    void Start()
    {
        transform.rotation = GetComponentInParent<GameObject>().gameObject.transform.rotation;
        transform.SetParent(null);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
